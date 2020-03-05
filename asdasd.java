class funxfd {

    public static void main(String[] args){
            int a[]  = new int[]{1,2,3,4,5,6,7,8,9,10,1,2,3};
            int x = a.length ; int y = 1;
            int result_int = 1;
            int res[] = new int[x];
            boolean condition;
            for (x = 0;x < 10;x++) {
                //boolean condition;
                //condition = (a[x] == 5);
                res[x] = (true ? 1 : 0);
                System.out.print(res[x]);
                res[x] = result_int;
            }
            //System.out.print(res);


    }

    //@Override
    //public void start(Stage primaryStage) {

    //}
}
