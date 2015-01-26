NAME	= viewer

CC	= g++

RM	= rm -f

SRCDIR	= src/

INCDIR	= inc/

LIBINC	= ProceduralNoise/inc/

OBJDIR	= obj/

LIBDIR 	= lib/

LIBNAME = libNoise.a

SRCS	= main.cpp \
	  Render.cpp

OBJS	= $(addprefix $(OBJDIR), $(SRCS:.cpp=.o))

INCCOMP	= -I $(INCDIR) -I $(LIBINC)

CXXFLAGS	= -O2 -march=native -std=c++11

LIB	= -L$(LIBDIR) -lNoise

LDFLAGS	= -lsfml-graphics -lsfml-window -lsfml-system

dummy	:= 	$(shell test -d $(OBJDIR) || mkdir $(OBJDIR)) \
		$(shell test -d $(LIBDIR) || mkdir $(LIBDIR))

$(OBJDIR)%.o:	$(SRCDIR)%.cpp
	$(CC) $(CXXFLAGS) $(INCCOMP) -o $@ -c $<

$(NAME): $(OBJS)
	make -C ProceduralNoise/ all
	mv ProceduralNoise/$(LIBNAME) $(LIBDIR)
	$(CC) -o $(NAME) $(OBJS)  $(LDFLAGS) $(LIB)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
