CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

TARGET = Serialization

SRCS = main.cpp Base.cpp A.cpp B.cpp C.cpp
OBJS = $(SRCS:%.cpp=.obj/%.o)

$(TARGET) : $(OBJS)
	$(CXX) $(OBJS) -o $@
 
.obj/%.o : %.cpp Base.hpp A.hpp B.hpp C.hpp Makefile
	@if [ ! -d .obj ]; then 	mkdir -p $(@D); fi
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY : clean
clean :
	rm -rf .obj

fclean : clean
	rm -rf $(TARGET)

re : fclean $(TARGET)