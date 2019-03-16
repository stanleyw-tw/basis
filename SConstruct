# define the flags
vars = Variables()
vars.Add(BoolVariable("BUILD_SOLUTION",
                      "Thesolution will be build",
                      False))

vars.Add("CCFLAGS", "cxx compiler flags",
         default="-g -std=c++14 -Wall -pedantic -Wextra \
                  -Wcast-qual -Wconversion -Wformat=2 \
                  -Wformat-nonliteral -Wformat-security -Winit-self  \
                  -Wmissing-format-attribute \
                  -Wmissing-include-dirs -Wpacked -Wredundant-decls \
                  -Wswitch-default -Wswitch-enum -Wunreachable-code -Wunused \
                  -Wno-unused-parameter")

dbg = Environment(variables=vars)

mycontext = "examples"

dbg.Program('main', ['main.cpp',
                     "test-methods.cpp",
                     "{}/diagonal-difference.cpp".format(mycontext),
                     "{}/count-elements.cpp".format(mycontext),
                     "{}/graybox-problem.cpp".format(mycontext),
                     "{}/sum-of-array.cpp".format(mycontext),
                     "{}/unique-sum-of-array.cpp".format(mycontext),
                     "{}/running-median.cpp".format(mycontext),
                     "{}/Bob.cpp".format(mycontext)],
            LIBS=[],
            LIBPATH=[],
            CPPPATH=["{}".format(mycontext)])
