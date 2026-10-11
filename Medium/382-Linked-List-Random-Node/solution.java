if(this.randN == null)
    {
        this.randN = this.head;
        return this.randN.val;
    }
    if(this.randN.next == null)
    {
        this.randN = this.head;
    }
    else
    {
        this.randN = this.randN.next;
    }

    return this.randN.val;
