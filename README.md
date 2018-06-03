# Call C++ code from python using the Boost libraries
In this short tutorial, I will show you how to call C++ code from python using [Boost](https://www.boost.org/).  I present a very simple example; raising a base to a power (exponentiation).  However, the methods I present can be generalized to myriad applications using more elaborate C++ interfaces/libraries/etc...

## Dependencies (version)
* `cmake` (3.5.1)
* `libboost-dev` (or equivalent if not using debian) (1.58.0)
* `python` (2.7.12)
* `gcc` (or another C++ compiler) (5.4.0)
* `make` (or equivalent if not using Linux) (4.1)
* `pytest`\* (3.6.0)

\*`pytest` is a python module used for unit-testing andis strictly optional.  The other dependencies are required.

## Building the package
From `path_to_repo`, the top directory of the project, execute the following from the command line:

```bash
mkdir build ; cd build ; cmake .. ; make ; make install
```

`make install` is optional \( and may require superuser privileges, like `sudo` \); it installs the package alongside other site-packages (i.e. those from `pip`).  If you choose not to run `make install`, you can add the `build` directory to `$PYTHONPATH`.

The end-products of the build stage are:

* a shared object library containing the wrapped C++ code, callable from python: `pyRTP.so`
* a test executable for verifying the C++ code is functional: `test_cpp_rtp`

## Unit testing
After installing `pyRTP` using EITHER:

* `make install` from `path_to_repo/build` OR
* `export PYTHONPATH=path_to_repo/build:$PYTHONPATH` from the command line

you are ready-to-rock!

I use `pytest` to unit test the build.  From the test directory, you can type

```bash
pytest test.py
```

and you should see the following output:

```bash
========================================================== test session starts ==========================================================
platform linux2 -- Python 2.7.12, pytest-3.6.0, py-1.5.3, pluggy-0.6.0
rootdir: /home/joe/github/call-cpp-from-python-with-boost/test, inifile:
collected 2 items                                                                                                                       

test.py ..                                                                                                                        [100%]

======================================================= 2 passed in 0.04 seconds ========================================================
```

which indicates that the two provided unit tests both pass.  Feel free to play around with it!
