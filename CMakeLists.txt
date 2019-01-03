cmake_minimum_required(VERSION 3.13)
project(proj2)

set(CMAKE_CXX_STANDARD 14)

add_executable(proj2 main.cpp MySerialServer.cpp MySerialServer.h ClientHandler.h MyClientHandler.cpp MyClientHandler.h CacheManager.h FileCacheManager.cpp FileCacheManager.h Server.h Solver.h StringReverser.cpp StringReverser.h Searchable.h Searcher.h MyParallelServer.cpp MyParallelServer.h State.cpp State.h SearchSolver.cpp SearchSolver.h Matrix.cpp Matrix.h ShortestPathSolver.cpp ShortestPathSolver.h ConvertSolver.cpp ConvertSolver.h)