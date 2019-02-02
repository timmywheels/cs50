int hash_function(char* key)
{
    // Hash on first letter of string
    int hash = toupper(key[0]) - 'A';
    return hash % SIZE;
}