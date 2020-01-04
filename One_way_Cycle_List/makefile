objs = $(patsubst %.c, %.o, $(wildcard *.c))

table : $(objs)
	gcc $< -o $@
%.o : %.c

.PHONY : clean
clean :
	rm table *.o
