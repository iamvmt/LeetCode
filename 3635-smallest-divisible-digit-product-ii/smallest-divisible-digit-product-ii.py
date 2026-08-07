class Solution:
    def smallestNumber(self, num: str, t: int) -> str:

        def freeSlotsFiller(n, l):
            filled = ""

            for i in range(9, 1, -1):
                while n % i == 0:
                    filled += str(i)
                    n //= i

            while len(filled) < l:
                filled += '1'

            return filled[::-1]

        n = len(num)

        # Check whether t contains any prime factor
        # other than 2, 3, 5 and 7.
        temp = t

        for primeFact in {2, 3, 5, 7}:
            while temp % primeFact == 0:
                temp //= primeFact

        if temp != 1:
            return '-1'

        # remainingFactor[i] = factor of t still required
        # after keeping the first i digits unchanged.
        remainingFactor = [t] * (n + 1)

        for i in range(n):
            digit = int(num[i])

            if digit == 0:
                break

            remainingFactor[i + 1] = (
                remainingFactor[i]
                // gcd(remainingFactor[i], digit)
            )

        # num itself already satisfies the requirement.
        if remainingFactor[n] == 1:
            return num

        # We cannot preserve a prefix containing zero.
        zeroPos = num.find('0')
        zeroIdx = n - 1

        if zeroPos != -1:
            zeroIdx = zeroPos

        # Change the rightmost possible position so that
        # the resulting number stays as small as possible.
        for i in range(zeroIdx, -1, -1):

            req = remainingFactor[i]
            freeSlots = n - i - 1

            # Try the smallest digit larger than num[i].
            for digit in range(int(num[i]) + 1, 10):

                furtherRequired = (
                    req // gcd(req, digit)
                )

                requiredNum = freeSlotsFiller(
                    furtherRequired,
                    freeSlots
                )

                if len(requiredNum) == freeSlots:
                    return (
                        num[:i]
                        + str(digit)
                        + requiredNum
                    )

        # No n-digit answer exists.
        # Build the smallest valid (n + 1)-digit number.
        return freeSlotsFiller(t, n + 1)