String compression

class Solution {
public:
    int compress(vector<char>& chars) {

        int n = chars.size();

        int read = 0;
        int write = 0;

        while (read < n) {

            char current = chars[read];
            int count = 0;

            // Count consecutive occurrences
            while (read < n && chars[read] == current) {
                read++;
                count++;
            }

            // Write character
            chars[write++] = current;

            // Write count if greater than 1
            if (count > 1) {

                string cnt = to_string(count);

                for (char c : cnt)
                    chars[write++] = c;
            }
        }

        return write;
    }
};

/*
Instead of looking at characters one by one,

look at

Groups of equal characters.

Example

aaabbcccc

Think of it as

aaa

bb

cccc

Process one group at a time.

For each group,

write

character

count (if >1)

Move to the next group.

Step 4 : Dry Run

Example

chars

a a b b c c c

Initially

read = 0

write = 0
Group 1
a a

Count

2

Write

a

Array

a

write = 1

Now write count

2

Array

a 2

write = 2

Group 2
b b

Count

2

Write

b

Array

a 2 b

Then

2

Array

a 2 b 2
Group 3
c c c

Count

3

Write

c

Then

3

Final

a 2 b 2 c 3

Length

6
What if count = 1?

Example

a

Don't write

a1

Just write

a

Only repeated characters get a count.

What if count > 9?

Example

aaaaaaaaaaaa

12 times.

We should write

a12

Notice

12

has two digits.

So write

1

2

separately.

*/