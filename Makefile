CC = g++
ODIR = obj
PROG = labyrinth
CXXFLAG = -std=c++11

$(PROG) : $(ODIR) $(ODIR)/algorithm.o $(ODIR)/utils.o $(ODIR)/main.o
	$(CC) -o $@ $(ODIR)/algorithm.o $(ODIR)/utils.o $(ODIR)/main.o $(CXXFLAG)

$(ODIR)/algorithm.o : ./src/algorithm.cpp ./include/algorithm.h
	$(CC) -c $< -o $@ $(CXXFLAG)

$(ODIR)/utils.o : ./src/utils.cpp ./include/utils.h ./include/Node.h ./include/Point.h
	$(CC) -c $< -o $@ $(CXXFLAG)

$(ODIR)/main.o : ./src/main.cpp ./include/utils.h ./include/algorithm.h
	$(CC) -c $< -o $@ $(CXXFLAG)

$(ODIR) :
	if [ ! -d $(ODIR) ]; then mkdir $(ODIR); fi

.PHONY : clean
clean :
	if [ -d $(ODIR) ]; then rm $(ODIR) -r; fi
	if [ -f $(PROG) ]; then rm $(PROG); fi
