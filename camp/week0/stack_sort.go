package week0

import "fmt"

type Stack interface {
	Push(v interface{})
	Pop() interface{}
	Top() interface{}
	IsEmpty() bool
	Flush()
	Print()
}

type ArrayStack struct {
	top  int
	data []interface{}
}

func NewArrayStack() *ArrayStack {
	return &ArrayStack{
		top:  -1,
		data: make([]interface{}, 0, 32),
	}
}

func (this *ArrayStack) IsEmpty() bool {
	if this.top < 0 {
		return true
	}
	return false
}

func (this *ArrayStack) Push(v interface{}) {
	if this.top < 0 {
		this.top = 0
	} else {
		this.top += 1
	}
	if this.top > len(this.data)-1 {
		this.data = append(this.data, v)
	} else {
		this.data[this.top] = v
	}
}

func (this *ArrayStack) Pop() interface{} {
	if this.IsEmpty() {
		return nil
	}
	v := this.data[this.top]
	this.top -= 1
	return v
}

func (this *ArrayStack) Top() interface{} {
	if this.IsEmpty() {
		return nil
	}
	return this.data[this.top]
}

func (this *ArrayStack) Flush() {
	this.top = -1
}

func (this *ArrayStack) Print() {
	if this.IsEmpty() {
		fmt.Println("empty stack")
	} else {
		for i := this.top; i >= 0; i-- {
			fmt.Println(this.data[i])
		}
	}
}

func StackSort(r *ArrayStack) {
	// 对无序栈进行排序

	// 申请一个临时栈
	s := NewArrayStack()
	// 若待排序栈为空,则不做操作
	if r.IsEmpty() {
		return
	}
	// 借助临时变量tmp保存待排元素
	tmp := r.Pop()

	for !r.IsEmpty() || (!s.IsEmpty() && s.Top().(int) > tmp.(int)) {
		// !s.IsEmpty() && s.Top > tmp条件很关键
		// 加上!s.IsEmpty()是为了防止r只有一个元素的情况
		if s.IsEmpty() || s.Top().(int) <= tmp.(int) {
			s.Push(tmp)
			tmp = r.Pop()
		} else {
			r.Push(s.Pop())
		}
	}
	// 将最大的值入栈
	s.Push(tmp)
	// 将临时栈的以排好序的元素倒回r
	for !s.IsEmpty() {
		r.Push(s.Pop())
	}
}
