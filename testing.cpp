#include "JSONlang.h"


PROGRAM_BEGIN
PRINT "Welcome to the demonstation\n"

JSON(book) = OBJECT {
    KEY(title) : STRING("Gone Girl"),
    KEY(published) : NUMBER(2012),
    KEY(type) : STRING("Thriller"),
    KEY(author) : OBJECT{
        KEY(firstname) : STRING("GILLIAN"),
        KEY(sirname) : STRING("FLYNN"),
        KEY(age) : NUMBER(45)
    },
    KEY(sus) : ARRAY [ NUMBER(20), NUMBER(19.5), NUMBER(19), NUMBER(20),
    NUMBER(19), NUMBER(18.5), NUMBER(19)]
}

JSON(book2) = OBJECT {
    KEY(title) : STRING("Gone Girl"),
    KEY(published) : NUMBER(2012),
    KEY(type) : STRING("Thriller"),
    KEY(author) : OBJECT{
        KEY(firstname) : STRING("GILLIAN"),
        KEY(sirname) : STRING("FLYNN"),
        KEY(age) : NUMBER(45)
    },
    KEY(sus) : STRING("sus")
}

JSON(week_temperatures) = ARRAY [
    NUMBER(20), NUMBER(19.5), NUMBER(19), NUMBER(20),
    NUMBER(19), NUMBER(18.5), NUMBER(19)
]

JSON(week_temperatures2) = ARRAY [
    NUMBER(20), NUMBER(19.5), NUMBER(19), NUMBER(20),
    NUMBER(19), NUMBER(20.5), NUMBER(19)
]


JSON(num) = NUMBER(61) - NUMBER(12);
PRINT "\nnum == " PRINT num

PRINT "\nbook and book2 is the same?\n" 
JSON(res) = book == book2
PRINT res

PRINT week_temperatures[1]

PRINT book["sus"]

PRINT "\nTHE END\n"
PROGRAM_END