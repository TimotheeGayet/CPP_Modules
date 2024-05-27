CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

TARGET = btc

SRCS = srcs/main.cpp srcs/parsing.cpp srcs/Date/Date.cpp
INCLUDES = srcs/BitcoinExchange.hpp
OBJS = $(SRCS:%.cpp=.obj/%.o)

$(TARGET) : $(OBJS)
	$(CXX) $(OBJS) -o $@

.obj/%.o : %.cpp Makefile BitcoinExchange.hpp
	@if [ ! -d .obj ]; then mkdir -p $(@D); fi
	$(CXX) $(CXXFLAGS) -c $< -I $(INCLUDES) -o $@

.PHONY : clean
clean :
	rm -rf .obj

fclean : clean
	rm -rf $(TARGET)

re : fclean $(TARGET)
