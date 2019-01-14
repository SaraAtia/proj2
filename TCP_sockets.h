//
// Created by sara on 14/01/19.
//

#ifndef PROJ2_TCP_SOCKETS_H
#define PROJ2_TCP_SOCKETS_H


// if you use this code in your project, remember to use
// #ifndef, #define, #endif
// also, make sure to seperate implementation (.cpp) from header (.h)

// it is also possible and recommended to seperate the exceptions
// declarations to a separate file

// you need: MyExceptions.h, Sockets.h, Sockets.cpp

// of course, remove the main() function

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cerrno>
#include <string>
#include <system_error>
#include <stdexcept>


namespace posix_sockets
{
    class timeout_exception : public std::runtime_error
    {
    public:
        timeout_exception(const char* msg) : std::runtime_error(msg){}
        timeout_exception(std::string msg) : std::runtime_error(msg){}
    };

    class illegal_state_exception : public std::logic_error
    {
    public:
        illegal_state_exception(std::string msg) : std::logic_error(msg){}
    };


    // struct defining general socket, with general operations (open and close)
    // opening is done in the constructor.
    // the socket is not automatically closed in the destructor, so that the object
    // can be passed as a parameter (possibly to another thread)
    struct TCP_socket
    {
        int sock_fd;
        TCP_socket()
        {
            sock_fd = socket(AF_INET, SOCK_STREAM, 0);
            if (sock_fd < 0)	{
                throw std::system_error(std::error_code(errno, std::generic_category()), "failure on opening socket");
            }
        }

        TCP_socket(int open_sock_fd)
        {
            this->sock_fd = open_sock_fd;
        }

        void close()
        {
            if (::close(sock_fd) < 0)	{
                throw std::system_error(std::error_code(errno, std::generic_category()), "failure on closing socket");
            }
        }

        void settimeout(int sec, int usec = 0)
        {
            timeval timeout;
            timeout.tv_sec = sec;
            timeout.tv_usec = usec;

            // setting socket option for recieve timeout
            if (setsockopt(sock_fd, SOL_SOCKET, SO_RCVTIMEO,
                           (char *)&timeout, sizeof(timeout)) == -1)	{
                throw std::system_error(std::error_code(errno, std::generic_category()), "failure on setsockopt");
            }
        }
    };

    class TCP_client
    {
        TCP_socket sock;
    public:
        // It makes sense to create another constructor that
        // will create a client from scratch

        TCP_client(TCP_socket sock) : sock(sock) {}

        // you should definitely use you own logic here
        // suggestions are - read_until (char), read_min(int)
        // read_line, etc.
        // you can obviously define a write (or send) method
        std::string read(int n)
        {
            char* buffer = new char[n + 1];
            int read_len = ::read(sock.sock_fd, buffer, n);
            if (read_len < 0)	{
                if (errno == EAGAIN || errno == EWOULDBLOCK)	{
                    throw timeout_exception("timeout on read");
                }
                throw std::system_error(std::error_code(errno, std::generic_category()), "error on read");
            }

            buffer[n] = 0;
            std::string output = std::string(buffer);
            delete buffer;
            return output;
        }

        void settimeout(int sec, int usec = 0)
        {
            sock.settimeout(sec, usec);
        }

        void close()
        {
            sock.close();
        }

        int get_sock()  {
            return sock.sock_fd;
        }
    };

    class TCP_server
    {
        TCP_socket sock;
    public:
        TCP_server(int port)
        {
            sockaddr_in addr_in;
            addr_in.sin_family = AF_INET;
            addr_in.sin_port = htons(port);
            addr_in.sin_addr.s_addr = INADDR_ANY;

            if (bind(sock.sock_fd, (sockaddr *)&addr_in, sizeof(addr_in)) == -1)	{
                throw std::system_error(std::error_code(errno, std::generic_category()), "failure on bind");
            }
        }

        void listen(int max_lis)
        {
            if (::listen(sock.sock_fd, max_lis) == -1)	{
                throw std::system_error(std::error_code(errno, std::generic_category()), "error on listen");
            }
        }

        void settimeout(int sec, int usec = 0)
        {
            sock.settimeout(sec, usec);
        }

        TCP_client accept()
        {
            sockaddr_in addr;
            socklen_t len = sizeof(addr);
            int client_sock_fd = ::accept(sock.sock_fd, (sockaddr*)&addr, &len);
            if (client_sock_fd < 0)	{
                // eagain and ewouldblock are errors normally hapenning on timeouts
                if (errno == EAGAIN || errno == EWOULDBLOCK)	{
                    throw timeout_exception("timeout on accept");
                }	else	{
                    throw std::system_error(std::error_code(errno, std::generic_category()), "error on accept");
                }
            }

            TCP_socket client_sock(client_sock_fd);

            // in unix, client socket have their parents' timeout
            // so we set the timeout to 0 (effectively - infinity)
            // for newly created sockets
            client_sock.settimeout(0);
            return client_sock;
        }

        void close()
        {
            sock.close();
        }
    };
}


#endif //PROJ2_TCP_SOCKETS_H
