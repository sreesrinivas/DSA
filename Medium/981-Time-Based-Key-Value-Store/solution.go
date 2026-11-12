var keys, vals [40]string // list of unique keys and values, its index in the list is their id
var stamps [40][63]uint32 // upper 24 bits holds the timestamp, lower 8 bits holds the value id

type TimeMap struct{ k, v int } // number of unique keys and values currently living in the lists

func Constructor() TimeMap { return TimeMap{} }

func (this *TimeMap) Set(key string, val string, stamp int) {
	v := slices.Index(vals[:this.v], val)
	if v == -1 { // new value
		v = this.v
		vals[this.v] = val
		this.v++
	}
	entry := uint32(stamp<<8 | v)
    // stamps list is 1-based, so that stamps[0] is always empty
	k := slices.Index(keys[:this.k], key) + 1
	if k == 0 { // new key
		keys[this.k] = key
		this.k++
		stamps[this.k][0] = 1
		stamps[this.k][1] = entry
		return
	}
	if stamps[k][stamps[k][0]]&255 == uint32(v) { // same value as last entry, reuse older timestamp
		return
	}
	stamps[k][0]++
	stamps[k][stamps[k][0]] = entry
}

func (this *TimeMap) Get(key string, stamp int) string {
	row := &stamps[slices.Index(keys[:this.k], key)+1]
	limit := uint32(stamp<<8 | 255)
	for i := row[0]; i >= 1; i-- {
		if row[i] <= limit {
			return vals[row[i]&255]
		}
	}
	return ""
}
