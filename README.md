# Rust-vs-Cpp
A casual comparison of Rust to C++ in speed performance

## I asked ChatGPT to write a few matrix routines in Rust and made very minor tweeks to the code.  I then ported the code line by line to C++.  I compiled both using the general command line for compiling:

```
busysteve@somewhere:~/rdev$ rustc rust_matrix.rs 
busysteve@somewhere:~/rdev$ g++ -o cpp_matrix cpp_matrix.cpp

I ran them both in Linux run on an older i7 gen 8 laptop using the time command:

busysteve@somewhere:~/rdev$ time ./rust_matrix 
55 145 235 325 415 
145 451 757 1063 1369 
235 757 1279 1801 2323 
325 1063 1801 2539 3277 
415 1369 2323 3277 4231 
Done

real	0m5.534s
user	0m5.522s
sys	0m0.013s




busysteve@somewhere:~/rdev$ time ./cpp_matrix 
55 145 235 325 415 
145 451 757 1063 1369 
235 757 1279 1801 2323 
325 1063 1801 2539 3277 
415 1369 2323 3277 4231 
Done

real	0m2.078s
user	0m2.073s
sys	0m0.005s
```

## Now I realize that the general command line builds are not "optimal", so I did a little optimization:

```
busysteve@somewhere:~/rdev$ rustc -C debuginfo=0 -C opt-level=3 rust_matrix.rs
busysteve@somewhere:~/rdev$ time ./rust_matrix 
55 145 235 325 415 
145 451 757 1063 1369 
235 757 1279 1801 2323 
325 1063 1801 2539 3277 
415 1369 2323 3277 4231 
Done

real	0m0.412s
user	0m0.404s
sys	0m0.008s




busysteve@somewhere:~/rdev$ g++ -O3 -o cpp_matrix cpp_matrix.cpp
busysteve@somewhere:~/rdev$ time ./cpp_matrix 
55 145 235 325 415 
145 451 757 1063 1369 
235 757 1279 1801 2323 
325 1063 1801 2539 3277 
415 1369 2323 3277 4231 
Done

real	0m0.203s
user	0m0.195s
sys	0m0.009s

```
