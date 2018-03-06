CC = g++
ODIR = obj
PROG = main
CXXFLAG =

$(PROG) : $(ODIR) $(ODIR)/$(PROG).o
	$(CC) -o $@ $(ODIR)/$(PROG).o $(ODIR)/utils.o $(CXXFLAG)

$(ODIR)/utils.o : ./src/utils.cpp ./include/utils.h
	$(CC) -c $< -o $@ $(CXXFLAG)

$(ODIR)/$(PROG).o : ./src/main.cpp $(ODIR)/utils.o
	$(CC) -c $< -o $@ $(CXXFLAG)

$(ODIR) :
	if [ ! -d $(ODIR) ]; then mkdir $(ODIR); fi

.PHONY : clean
clean :
	if [ -d $(ODIR) ]; then rm $(ODIR) -r; fi
	if [ -f $(PROG) ]; then rm $(PROG); fi
