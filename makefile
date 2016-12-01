CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

ODIR = obj

DEPS = main.h BlackJack.h BlackJackHand.h BlackJackPlayer.h PlayingCard.h PlayingCardDeck.h

_OBJ = main.o BlackJack.o BlackJackHand.o BlackJackPlayer.o PlayingCard.o PlayingCardDeck.o
OBJ = $(patsubst %, $(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -o $@ $< $(LFLAGS)

blackjack: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(ODIR)/*.o *~ blackjack