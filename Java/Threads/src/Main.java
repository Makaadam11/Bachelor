public class Main {

    boolean flag = true;

    public synchronized void changeFlag() {
        this.flag = !this.flag;

        if (this.flag) {
            System.out.println("zwalniam blokady");
            notify();
            // notifyAll();
        }
    }

    public synchronized void print(String s) {
        while (!this.flag) {
            try {
                System.out.println("chciałbym wypisac " + s + " ale nie mam blokady wiec czekam");
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        changeFlag();
        for(int i=0; i<10; i++)
            System.out.println(i + " " + s);
    }


    public static void main(String[] args) throws InterruptedException {
        final Main m1 = new Main();
        //final Main m2 = new Main();

        Thread t1 = new Thread(new Runnable() {
            public void run() {
                for(int i=0; i<10; i++) {
                    m1.print("(" + i + ")" + " Pierwszy wątek");
                }
            }
        });

        Thread t2 = new Thread(new Runnable() {
            public void run() {
                for(int i=0; i<10; i++) {
                    m1.print("(" + i + ")" + " Drugi wątek");
                }
            }
        });

        Thread t3 = new Thread(new Runnable() {
            public void run() {
                for (int i=0; i<50; i++) {
                    try {
                        Thread.sleep(5000);
                    } catch (InterruptedException e) {
                        // TODO Auto-generated catch block
                        e.printStackTrace();
                    }
                    m1.changeFlag();
                }
            }
        });
        t1.start();
        t2.start();
        t3.start();
    }
}