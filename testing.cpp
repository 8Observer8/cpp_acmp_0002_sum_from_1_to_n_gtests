#include <gtest/gtest.h>

class LogicError : public std::logic_error {
public:

    LogicError( int argument ) : std::logic_error( "" ), m_argument( argument ) {

    }

    virtual const char *what( ) const throw () {
        return m_message.c_str( );
    }

    virtual ~LogicError( ) throw () {

    }

protected:
    int m_argument;
    std::string m_message;
};

class OutOfRange : public LogicError {
public:

    OutOfRange( int argument, int beginOfRange, int endOfRange ) : LogicError( argument ) {
        std::string str_argument, str_beginOfRange, str_endOfRange;

        str_argument = intToString( argument );
        str_beginOfRange = intToString( beginOfRange );
        str_endOfRange = intToString( endOfRange );

        m_message = "Argument " + str_argument + " doesn't hit in the range [" +
                str_beginOfRange + ", " + str_endOfRange + "]";
    }

private:

    std::string intToString( int number ) {
        std::stringstream stream;
        stream << number;
        return stream.str( );
    }
};

int sum( int n )  throw (OutOfRange);

TEST( test001, normalTest ) {
    int n = 0;
    int expected = 1;

    int actual = 0;
    ASSERT_NO_THROW({
                        actual = sum( n );
                    });
    ASSERT_EQ( expected, actual );
}

TEST( test002, normalTest ) {
    int n = 2;
    int expected = 3;

    int actual = 0;
    ASSERT_NO_THROW({
                        actual = sum( n );
                    });
    ASSERT_EQ( expected, actual );
}

TEST( test003, normalTest ) {
    int n = -1;
    int expected = 0;

    int actual = 0;
    ASSERT_NO_THROW({
                        actual = sum( n );
                    });
    ASSERT_EQ( expected, actual );
}

TEST( test004, normalTest ) {
    int n = -2;
    int expected = -2;

    int actual = 0;
    ASSERT_NO_THROW({
                        actual = sum( n );
                    });
    ASSERT_EQ( expected, actual );
}

TEST( test005, normalTest ) {
    int n = -3;
    int expected = -5;

    int actual = 0;
    ASSERT_NO_THROW({
                        actual = sum( n );
                    });
    ASSERT_EQ( expected, actual);
}

TEST( test006, normalTest ) {
    int n = -4;
    int expected = -9;

    int actual = 0;
    ASSERT_NO_THROW({
                        actual = sum( n );
                    });
    ASSERT_EQ( expected, actual );
}

TEST( test007, normalTest ) {
    int n = -5;
    int expected = -14;

    int actual = 0;
    ASSERT_NO_THROW({
                        actual = sum( n );
                    });
    ASSERT_EQ( expected, actual );
}

TEST( test008, normalTest ) {
    int n = -6;
    int expected = -20;

    int actual = 0;
    ASSERT_NO_THROW({
                        actual = sum( n );
                    });
    ASSERT_EQ( expected, actual );
}

TEST( test009, normalTest ) {
    int n = 5;
    int expected = 15;

    int actual = 0;
    ASSERT_NO_THROW({
                        actual = sum( n );
                    });
    ASSERT_EQ( expected, actual );
}

TEST( test010, normalTest ) {
    int n = 15;
    int expected = 120;

    int actual = 0;
    ASSERT_NO_THROW({
                        actual = sum( n );
                    });
    ASSERT_EQ( expected, actual );
}

TEST( test011, exeptionTest ) {
    int n = 10000;

    ASSERT_NO_THROW({
                        sum( n );
                    });
}

TEST( test012, exeptionTest ) {
    int n = -10000;

    ASSERT_NO_THROW({
                        sum( n );
                    });
}

TEST( test013, exeptionTest ) {
    int n = 10001;

    ASSERT_THROW({
                    sum( n );
                 }, OutOfRange);
}

TEST( test014, exeptionTest ) {
    int n = -10001;

    ASSERT_THROW({
                     sum( n );
                 }, OutOfRange);
}

int main( int argc, char *argv[] ) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS( );
}
