class Money
{
    private int rupees;
    private int paisa;
    public void setMoney(int r, int p)
    {
        rupees = r;
        paisa = p;
    }
    public void displayMoney()
    {
        System.out.print(rupees + "Rupee, " + paisa + "Paisa");
    }
    public void addMoney(Money m1, Money m2)
    {
        this.rupees = m1.rupees + m2.rupees;
        this.paisa = m1.paisa + m2.paisa;
        if(this.paisa >= 100)
        {
            this.rupees += this.paisa / 100;
            this.paisa %= 100;
        }
    }
}

public class MoneyTest
{
    public static void main(String args[])
    {
        Money money1 = new Money();
        Money money2 = new Money();
        Money totalMoney = new Money();
        
        money1.setMoney(10, 75);
        money2.setMoney(5, 50);
        
        totalMoney.addMoney(money1, money2);
        
        money1.displayMoney();
        System.out.print(" + ");
        money2.displayMoney();
        System.out.print(" = ");
        totalMoney.displayMoney();
        
    }
}