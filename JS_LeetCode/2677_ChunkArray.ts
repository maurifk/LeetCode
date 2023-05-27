function cchunk(arr: any[], size: number): any[][] {
  let res:any[][] = new Array(Math.floor(arr.length/size));
  for (let i = 0; i<Math.floor(arr.length/size); ++i){
    res[i] = [];
  }

  for(let i:number = 0; i < arr.length; ++i){
    res[Math.floor(i/size)].push(arr[i]);
  }

  return res;

};
