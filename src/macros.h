#ifndef CLUE_MACROS_H
#define CLUE_MACROS_H
// macros.h

#define swap(a,b,T) do{T temp = a; a = b; b = temp;}while(0)

#define cp(source, dest, size) for(int i=0; i<size; i++) dest[i] = source[i]

#endif /* end of include guard: CLUE_MACROS_H */
