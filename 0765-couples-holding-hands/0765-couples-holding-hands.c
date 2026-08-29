int minSwapsCouples(int* row, int rowSize) {
    int swaps = 0;
    for(int i = 0; i < rowSize; i += 2){
        int person1 = row[i];
        int partner = person1 ^ 1;
        if(row[i+1] != partner){
            for(int j = i + 2; j < rowSize; j++){
                if(row[j] == partner){
                    int temp = row[i + 1];
                    row[i + 1] = row[j];
                    row[j] = temp;
                    swaps++;
                    break;
                }
            }
        } 
    }
    return swaps;
}
