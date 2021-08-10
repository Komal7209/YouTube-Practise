var minFlipsMonoIncr = function(s) {
    let counter_one =0 , counter_flip = 0;
      for (let i of s){  // if we use for in here, then order of index change
          if (i == '1'){
              counter_one +=1;
          }
          else{
              counter_flip +=1;
          }
          counter_flip = Math.min(counter_one, counter_flip);
      }
      
      return counter_flip;
};