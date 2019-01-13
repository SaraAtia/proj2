cmake_minimum_required(VERSION 3.12)
project(proj2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(proj2 main.cpp MySerialServer.cpp MySerialServer.h ClientHandler.h MyClientHandler.cpp MyClientHandler.h CacheManager.h FileCacheManager.cpp FileCacheManager.h Server.h Solver.h Searchable.h Searcher.h MyParallelServer.cpp MyParallelServer.h State.cpp State.h SearchSolver.cpp SearchSolver.h Matrix.cpp Matrix.h ShortestPathSolver.cpp ShortestPathSolver.h ConvertSolver.cpp ConvertSolver.h Bfs.h Dfs.h  Astar.h TCP_sockets.cpp TCP_sockets.h)
