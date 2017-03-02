  void read_failure () {
    printf("\nac_reg::read_failure");
    stuckAt(Data, 20, 1, 0.1);
  }

  void write_failure() 
  { 
    printf("\nac_reg::write_failure");
    stuckAt(Data, 20, 1, 0.1);
  }
