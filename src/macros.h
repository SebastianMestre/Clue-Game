#ifndef CLUE_MACROS_H
#define CLUE_MACROS_H
// macros.h

#define swap(a,b,T) do{T temp = a; a = b; b = temp;}while(0)
#define purge_input_buffer() char c; while ((c = getchar()) != '\n' && c != EOF);

#endif /* end of include guard: CLUE_MACROS_H */
