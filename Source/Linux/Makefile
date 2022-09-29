all:
	rm -rfv build 
	mkdir -v build
	g++ -c -I./SFML-2.5.1/include/ src/Button.cpp src/Path.cpp src/PrizeState.cpp src/PureLinePath.cpp src/Reel.cpp src/ReelWrapper.cpp src/SlotMachine.cpp src/Source.cpp src/SpiningState.cpp src/State.cpp src/StaticState.cpp src/Symbol.cpp src/ZigZagLinePath.cpp  
	g++ Button.o Path.o PrizeState.o PureLinePath.o Reel.o ReelWrapper.o SlotMachine.o Source.o SpiningState.o State.o StaticState.o Symbol.o ZigZagLinePath.o -o build/sfml-app -L./SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
	rm Button.o Path.o PrizeState.o PureLinePath.o Reel.o ReelWrapper.o SlotMachine.o Source.o SpiningState.o State.o StaticState.o Symbol.o ZigZagLinePath.o
	cp -rf src/assets .
launch:
	export LD_LIBRARY_PATH=SFML-2.5.1/lib && build/sfml-app
clean: 
	rm -rv assets
	rm -rv build
