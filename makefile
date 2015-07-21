all:
	$(MAKE) -C graphics
	$(MAKE) -C Cards
clean:
	cd Cards && rm *.o cards
	cd graphics && rm *.o img
