#ifndef TABLE_H
#define TABLE_H

#include <stdbool.h>

/**
 * @defgroup table
 * 
 * @author Jesper Andersson
 * @date 05/12-2020
 * 
 * @brief Creating a table.
 * 
 * Creating a table by assigning a capacity of buckets and assigning values to
 * the buckets through the keys and values. While keeping check of which buckets
 * have been assigned a value through the bool used variable in the struct.
 * 
 * @{
 */

// The type for a bucket.
struct bucket
{
    int key;
    int value;
    bool used;
};

// The type for the table.
typedef struct table
{
    // The number of buckets.
    int capacity;
    // The bucket array.
    struct bucket *buckets;
} Table;

/**
 * @brief Create an empty table.
 * 
 * Create an empty table with the capacity for the given amount of buckets. This
 * where the space is allocated aswell.
 * 
 * @param capacity The capacity for buckets inside of the table.
 * @return The empty table.
 */
Table *table_create(int capacity);

/**
 * @brief Destroy the table.
 * 
 * Destroy the table by deallocating the table and the buckets inside of it.
 * 
 * @param tab The table which you want to deallocate/destroy.
 */
void table_destroy(Table *tab);

/**
 * @brief Lookup the value for a key and return false if the key is not found.
 * 
 * Find the bucket through the use of the internal function of
 * table.c find_bucket. If it exists and has been assigned a used value you
 * compare the values and return true if its correct. If it doesnt exist or 
 * it hasnt been assigned a used value it returns false.
 * 
 * @param tab The table in which the bucket resides.
 * @param key The key for the value you want to check.
 * @param value The value you are checking for.
 * 
 * @return True if the key is found and false if it isnt.
 */
bool table_lookup(Table *tab, int key, int *value);

/**
 * @brief Insert a key/value pair and overwrite the value if the key exists.
 * 
 * Find the bucket through the use of the internal function of
 * table.c find_bucket. it assigns the parameters to the bucket and sets the
 * used value to true.
 * 
 * @param tab The table in which you want to insert the bucket.
 * @param key The key for the bucket you want to assign a value to.
 * @param value The value you want to assign to the bucket.
 */
void table_insert(Table *tab, int key, int value);

/**
 *  @}
 */

#endif /* TABLE_H */