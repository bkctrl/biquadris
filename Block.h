
// you need to have individual init for each block since they are displayed differently 
// block has virtual init func that does nothing, specifics are implemented in its subclasses that override the init method

// block has a vector of pointers to cells called blockCells 
// this vector contains the coordinates the cells cover (cell contains itself's coordinate information inside cell class)

// cell knows about the changes
// grid cares about the changes (ex. to clear row(s))