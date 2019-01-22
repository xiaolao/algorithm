package camp

type Stack interface {
	Push(v interface{})
	Pop() interface{}
	IsEmpty() bool
	Top() interface{}
	Flush()
}
