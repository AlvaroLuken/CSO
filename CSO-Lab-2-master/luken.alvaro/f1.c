int f1(int x) {
    
    int z;
    if(x <= 15) {
        
        z = x;
        z = z >> 1;
        z = z+7;
        
        return z;
        
    }
    else{
        z = x;
    
    int y = 8*x;
    
    z = z << 2;
    y = z+y;
    z = x;
    z = z+z;
    z = z + y;
    
  //  x = x+y;
    
    return z;
    }
}