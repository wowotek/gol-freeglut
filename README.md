# Game Of Life - Freeglut

a simple Conway's Game of Life implemented in Freeglut 3 - C++

## Usage

I will put instruction for tested OS only. if you have solution for other OS. please add a pull requests

### Ubuntu 20.04

#### System Requirements

```shell script
sudo apt-get install freeglut3 freeglut3-dev
```

#### Compile

```shell script
./pymake compile
```

#### Run

```shell script
./pymake run
```

or

```shell script
./build/bin/gol
```

#### Installation (Optional -- Not Required)

you can install this to your machine by making a symbolic link or moving/copying it directly

```shell script
sudo mv build/bin/gol /usr/bin/gol
gol
```