#ifndef ARRAY_H
#define ARRAY_H

/**
 *@defgroup array
 * 
 *@author Jesper Andersson
 *@date 26/11-2020
 *
 *@brief Creating a two dimensional array
 *
 *This is a program made for creating and managing two dimensional arrays
 *with a struct representing the array and its data. With it you can edit and
 *view values at specific points in the array.
 *
 * @{
 */

// The type for a 2D array.
typedef struct array
{
    int n1;
    int n2;
    int *data;
} Array;

/**
 *@brief Create and return a zero array of size n1 rows by n2 columns.
 *
 *Allocates size to the array and initalizes the data to zero.
 *
 *@param n1 The number of rows intended for the array.
 *@param n2 The number of colums intended for the array.
 *@return An empty array.
 */
Array *array_create(int n1, int n2);

/**
 *@brief Destroy an array.
 *
 *Deallocates the struct Array and the data it contains.
 *
 *@param arr The array that will be deallocated.
 */
void array_destroy(Array *arr);

/**
 *@brief Get the number of rows.
 *
 *Get the number of rows by reading const struct Array and returning it.
 *
 *@param arr The array to read amount of rows from.
 *@return The number of rows.
 */
int array_rows(const Array *arr);

/**
 *@brief Get the number of columns.
 *
 *Get the number of columns by reading const struct Array and returning it.
 *
 *@param arr The array to read amount of columns from.
 *@return The number of columns.
 */
int array_columns(const Array *arr);

/**
 *@brief Return the value at row i1 and column i2 (zero-based indexing).
 *
 *Get the specified value from the two dimensional array by targeting the value
 *at i1 and i2 and return it.
 *
 *@param arr The array.
 *@param i1 The row the value is on.
 *@param i2 The column the value is on.
 *@return The value at the postion i1,i2.
 */
int array_get(const Array *arr, int i1, int i2);

/**
 *@brief Set the value at row i1 and column i2 (zero-based indexing).
 *
 *Set the specified value by targeting its position in the array and changing
 *the value/data.
 *
 *@param arr The array.
 *@param i1 The row of the value you change.
 *@param i2 the column of the value you change.
 *@param value The value you want to set.
 */
void array_set(Array *arr, int i1, int i2, int value);

/**
 *  @}
 */
#endif /* ARRAY_H */