/*
** EPITECH PROJECT, 2023
** my_str_to_word_array.h
** File description:
** str to zord array
*/


#ifndef MY_STR_TO_WORD_ARRAY_H_
    #define MY_STR_TO_WORD_ARRAY_H_
    #include <stdlib.h>
int my_check_number_of_words(char const *str);
int my_str_to_word_array_len(int *len_a, int *len_b, char const *str, int i);
void my_str_to_word_a_print(char const *str, int len, int *word, char **dest);
#endif /* MY_STR_TO_WORD_ARRAY_H_ */
