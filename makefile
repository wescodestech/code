all:
	$(MAKE) -C Cards
clean:
	cd Cards && rm *.o cards
