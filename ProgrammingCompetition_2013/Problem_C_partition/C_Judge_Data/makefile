DIR=${shell pwd}
SOURCE1=partyGames_zeil.cpp
SOURCE2=partygames.java
SOURCE3=
#
#TARGET1=$(SOURCE1:%.java=%)
#TARGET2=$(SOURCE2:%.java=%)
TARGET1=$(SOURCE1:%.cpp=%.exe)
TARGET2=$(SOURCE2:%.java=%)
TARGET3=$(SOURCE3:%.cpp=%.exe)
#
TESTINFILES=$(wildcard *.judge)
TESTOUTFILES=$(TESTINFILES:%.judge=%.out)
TESTOUT2FILES=$(TESTINFILES:%.judge=%.out2)
TESTOUT3FILES=$(TESTINFILES:%.judge=%.out3)

DIFFFILES=$(TESTINFILES:%.judge=%.diff)
DIFF3FILES=$(TESTINFILES:%.judge=%.diff3)



#JAVAPATH=/research/java/jdk1.5.0_05/bin/

all: ${DIFFFILES} ${TESTOUTFILES} ${TESTOUT2FILES}
#all: ${TESTOUTFILES}

%.diff: %.out %.out2
	diff -b $*.out $*.out2 > $*.diff
	wc $*.diff

%.diff3: %.out %.out3
	diff -b $*.out $*.out3 > $*.diff
	wc $*.diff3

%.out: %.judge $(TARGET1)
	./$(TARGET1) < $*.judge | tee $*.out

%.out2: %.judge $(TARGET2).class
	java $(TARGET2) $*.judge | tee $*.out2

%.out3: %.judge $(TARGET3).class
	./$(TARGET3) < $*.judge | tee $*.out3


%.exe: %.cpp
	g++ -g -o $@ $<

%.exe: %.c
	gcc -g -o $@ $<

%.class: %.java
	$(JAVAPATH)javac -g $<

clean:
	-rm *.exe *.class test*.*out


