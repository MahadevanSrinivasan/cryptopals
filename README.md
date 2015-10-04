# cryptopals

This repository is my attempt at solving [The matasano crypto challenges](http://cryptopals.com/). 
For the unaware, matasano crypto challenges are a series of cryptography specific programming 
challenges aimed to teach you the concepts. A possibly better explanation can be found 
[here](https://blog.pinboard.in/2013/04/the_matasano_crypto_challenges/).

I am trying to document my attempt on my [website](theshybulb.com) as well.

### Convert hex to base64
    make -f Makefile_s1c1
    ./s1c1.out ` < 1.txt `

### Fixed XOR
    make -f Makefile_s1c2
    ./s1c2.out ` < 2.txt `

### Single-byte XOR cipher
    make -f Makefile_s1c3
    ./s1c3.out ` < 3.txt `


### Detect single-character XOR
    make -f Makefile_s1c4
    ./s1c4.out ` < 4.txt `

### Implement repeating-key XOR
    make -f Makefile_s1c4
    ./s1c5.out "` < 5.txt `"

