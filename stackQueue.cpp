/*
 * 基于堆栈的队列
 */
class Queue {
    public:
        // 压入
        void push(int data) {
            m_i.push(data);
        }
        // 弹出
        void pop(void) {
            if(m_o.empty()) {
                if(m_i.empty()) {
                    throw underflow_error("队列下溢！");
                }
                while(! m_i.empty()) {
                    m_o.push(m_i.top()); 
                    m_i.pop();
                }
            }
            m_o.pop();
        }
        // 获取尾元素
        int back(void) {
            if(m_i.empty()) {
                if(m_o.empty()) {
                    throw underflow_error("队列下溢");
                }
                while(!m_o.empty()) {
                    m_i.push(m_o.top());
                    m_o.pop();
                }
            }
            return m_i.top();
        }
        // 获取首元素
        int front(void) {
            if(m_o.empty()) {
                if(m_i.empty()) {
                    throw underflow_error("队列下溢");
                }
                while(!m_i.empty()) {
                    m_o.push(m_i.top());
                    m_i.pop();
                }
            }
            return m_o.top();
        }
        // 判空
        bool empty(void) const {
            return m_i.empty() && m_o.empty();
        }
        // 大小
        int size(void) {
            return m_i.size() + m_o.size();
        }
    private:
        stack<int> m_i; // 输入栈
        stack<int> m_o; // 输出栈
};

