// if member class has pointer, do not use shallow copy
// use delete constructors (to make deep copy)
// so that pass by values will not free up the memories