# Caesar cipher command line implementation

## Usage

### Simple encryption (without dictionary)
```bash
$ echo "This is the usage" | caesar 12
Ftue ue ftq gemsq

$ echo "Ftue ue ftq gemsq" | caesar -12
This is the usage
```

### Dictionary encryption
```bash
$ echo "This is the usage" | caesar 12 "More Advanced Tutorial"
ahTs Ts chM nsAgM

$ echo "ahTs Ts chM nsAgM" | caesar -12 "More Advanced Tutorial"
This is the usage
```

### Mixing everything up!
```bash
$ echo "This is the usage" | ./caesar 16 "Dictionary" | ./caesar 22 | ./caesar 3 "super"

Pdro ro uda qokca

$ echo "Pdro ro uda qokca" | ./caesar -3 "super" | ./caesar -22 | ./caesar -16 "Dictionary"
This is the usage
```
