import java.util.*;

enum Action {
    READ,
    WRITE
}

class Command {

    int processor;
    Action command;

    public Command (int proc, Action comm) {
        this.processor = proc;
        this.command = comm;
    }

    public String toString() {
        return "(" + this.processor + " - " + this.command + ")";
    }

}

public class Mesi {

    public static final int N = 4;

    // (Proc, State)
    public static Map<Integer, String> procs = new HashMap<>();

    // indicele procesorului care a fost ultima data in E sau in M
    public static int lastInMorE = 0;

    public static boolean allInInvalid() {
        ArrayList<String> values = new ArrayList<>(procs.values());

        for (String val : values) {
            if ( !val.equals("I") )
                return false;
        }

        return true;
    }

    public static boolean oneInExclusive() {
        Set<String> values = new HashSet<>(procs.values());

        return values.contains("E");
    }

    public static boolean oneInShared() {
        Set<String> values = new HashSet<>(procs.values());

        return values.contains("S");
    }

    public static boolean oneInModify() {
        Set<String> values = new HashSet<>(procs.values());

        return values.contains("M");
    }

    public static boolean allInShared() {
        ArrayList<String> values = new ArrayList<String>(procs.values());

        for (String val : values)
            if (!val.equals("S"))
                return false;

        return true;
    }

    public static void main(String[] args) {
        ArrayList<Command> inputs = new ArrayList<>();

        inputs.add(new Command(1, Action.READ));
        inputs.add(new Command(2, Action.READ));
        inputs.add(new Command(3, Action.READ));
        inputs.add(new Command(4, Action.READ));
        inputs.add(new Command(1, Action.READ));
        inputs.add(new Command(1, Action.WRITE));
        inputs.add(new Command(1, Action.READ));
        inputs.add(new Command(2, Action.WRITE));
        inputs.add(new Command(3, Action.READ));
        inputs.add(new Command(4, Action.WRITE));
        inputs.add(new Command(4, Action.READ));

        System.out.println("Inputs: " + inputs);
        for (int i = 1; i <= N; i++)
            procs.put(i, new String("I"));

        System.out.println("Processors: " + procs);

        int time = 0;
        System.out.println("t" + time + " : " + procs);

        time = time + 1;
        for (Command action : inputs) {

            int proc = action.processor;
            Action command = action.command;
            String mag_action = new String("-");
            String data_src = new String("-");

            if (command == Action.READ) {
                if (allInInvalid()) {
                    procs.put(proc, new String("E"));
                    mag_action = "BusRd";
                    data_src = "Mem";
                    lastInMorE = proc;
                } else if (oneInExclusive()) {
                    boolean changed = false;
                    for (int i = 1; i <= N; i++) {
                        if ((i != proc) && (procs.get(i).equals("E"))) {
                            procs.put(i, new String("S"));
                            changed = true;
                        }
                    }
                    if (changed) {
                        procs.put(proc, new String("S"));
                        mag_action = "Flush";
                        data_src = "Cache" + lastInMorE;
                    }

                } else if ( oneInShared() ) {
                    if ( !allInShared() ) {
                        procs.put(proc, new String("S"));
                        mag_action = "Flush*";
                        data_src = "Cache" + lastInMorE;
                    }

                } else if (oneInModify()) {
                    if (procs.get(proc).equals("M") == false) {
                        // ex. t8
                        for (int i = 1; i <= N; i = i + 1) {
                            if ((i == proc) || (procs.get(i).equals("M")))
                                procs.put(i, new String("S"));
                        }
                        mag_action = "BusRd";
                        data_src = "Cache" + lastInMorE;
                    }
                }
            } else if (command == Action.WRITE) {
                data_src = "Flush";
                if (allInShared())
                    data_src = "Flush*";

                for (int i = 1; i <= N; i++) {
                    if (i == proc) {
                        procs.put(i, new String("M"));
                        lastInMorE = proc;
                    } else {
                        procs.put(i, new String("I"));
                    }
                }
                mag_action = "BusRdX";
            }

            System.out.println("t" + time + " : " + procs + " (" + mag_action + " , " + data_src + ")");
            time = time + 1;
        }
    }
}

