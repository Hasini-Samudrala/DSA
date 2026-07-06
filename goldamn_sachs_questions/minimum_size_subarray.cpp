int left = 0;
int sum = 0;
int ans = INT_MAX;

for (int right = 0; right < n; right++) {

    sum += nums[right];

    while (sum >= target) {

        ans = min(ans, right - left + 1);

        sum -= nums[left];
        left++;
    }
}


/*Minimum Size Subarray Sum

Problem

arr

2 3 1 2 4 3

Target = 7

Find the shortest subarray

whose sum

>=7
Intuition

Keep expanding

until

sum>=7

Now we've achieved the goal.

Can we make it smaller?

Shrink.

Dry Run

Initially

sum=0

L=0

R=0

2

sum=2

Not enough.

R=1

2 3

sum=5

Still not enough.

R=2

2 3 1

sum=6

Still.

R=3

2 3 1 2

sum=8

Finally valid.

Answer

length=4

Now shrink.

Remove

2

Window

3 1 2

sum=6

Invalid.

Stop shrinking.

Expand.

R=4

3 1 2 4

sum=10

Valid.

Answer

4

Shrink.

Remove

3

sum=7

Still valid.

Answer

3

Shrink again.

Remove

1

sum=6

Invalid.

Stop.

Continue.

Eventually answer becomes

2

Window

4 3
 */