#ifndef SOURCE_LOCATION_H
#define SOURCE_LOCATION_H

struct SourceLocation {

    const int rawPosition;
    const int lineNumber;
    const int column;
};

#endif