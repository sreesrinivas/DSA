class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        # sort intervals (meetings) by end time
        intervals.sort(key=lambda x: x[1])
        
        numberOfScheduledMeetings = len(intervals)
        prev = 0

        # We need to keep at least one meeting in our schedule
        meetingsToKeep = 1

        for cur in range(1, numberOfScheduledMeetings):
            '''
            start of second interval >= end of first interval
            i.e. second meeting starts after the first meeting ends
            i.e. NO OVERLAP
            So, we can keep the first meeting and move forward with our comparison 
            We also add this meeting to the tally of how many meetings
            we can keep in our schedule
            '''
            if intervals[cur][0] >= intervals[prev][1]:
                meetingsToKeep += 1

                # we can keep the previous meeting
                # So, now we check if we can keep the current one
                prev = cur

        # subtracting the number of meetings we can keep from total meetings
        # gives us the number of meetings we can remove from our schedule
        meetingsToRemove = numberOfScheduledMeetings - meetingsToKeep
        
        return meetingsToRemove
