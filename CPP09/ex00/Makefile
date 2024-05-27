CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -g3

TARGET = btc

SRCS = srcs/main.cpp srcs/BitcoinExchange.cpp srcs/parsing.cpp
INCLUDES = srcs/BitcoinExchange.hpp
INCLUDES_COMPIL = $(INCLUDES:%.hpp=-I%.hpp)
OBJS = $(SRCS:%.cpp=.obj/%.o)

$(TARGET) : $(OBJS)
	$(CXX) $(OBJS) -o $@

.obj/%.o : %.cpp Makefile $(INCLUDES)
	@if [ ! -d .obj ]; then mkdir -p $(@D); fi
	$(CXX) $(CXXFLAGS) -c $< $(INCLUDES_COMPIL) -o $@

.PHONY : clean
clean :
	rm -rf .obj

fclean : clean
	rm -rf $(TARGET)

re : fclean $(TARGET)
