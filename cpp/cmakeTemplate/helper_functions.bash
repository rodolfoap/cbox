# Run this as...
#	$ source helper_functions.bash
# Or add the function to your .bashrc

x () {
    [ -f .go ] && {
        source .go $@
    };
    [ -f Makefile ] && {
        make $@
    }
}
