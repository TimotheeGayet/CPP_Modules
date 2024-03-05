CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

TARGET = phonebook

SRCS = ex01.cpp Contact.cpp PhoneBook.cpp
OBJS = $(SRCS:%.cpp=.obj/%.o)

$(TARGET) : $(OBJS) 
	$(CXX) $(OBJS) -o $@

.obj/%.o : %.cpp PhoneBook.hpp Contact.hpp Makefile
	@if [ ! -d .obj ]; then 	mkdir -p $(@D); fi
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY : clean
clean :
	rm -rf .obj

fclean : clean
	rm -rf $(TARGET)

re : fclean $(TARGET)