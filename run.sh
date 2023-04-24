#! /usr/bin/bash


# clang++ -pthread -fsanitize=address -fsanitize=undefined -std=c++20 -g -Wall -Werror -gdwarf-4 Tests/Constructors.cpp -lgtest -lgtest_main -o TestsOutput/constructors.out
# ./TestsOutput/constructors.out

# clang++ -pthread -fsanitize=address -fsanitize=undefined -std=c++20 -g -Wall -Werror -gdwarf-4 Tests/Comparison.cpp -lgtest -lgtest_main -o TestsOutput/comparison.out
# ./TestsOutput/comparison.out

# clang++ -pthread -fsanitize=address -fsanitize=undefined -std=c++20 -g -Wall -Werror -gdwarf-4 Tests/BinaryPlusMinus.cpp -lgtest -lgtest_main -o TestsOutput/BinaryPlusMinus.out
# ./TestsOutput/BinaryPlusMinus.out

clang++ -pthread -fsanitize=address -fsanitize=undefined -std=c++20 -g -Wall -Werror -gdwarf-4 Tests/BinaryMultDiv.cpp -lgtest -lgtest_main -o TestsOutput/BinaryMultDiv.out
./TestsOutput/BinaryMultDiv.out