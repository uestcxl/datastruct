//php实现的链表
<?php
    class List{
        public $data;
        public $next;
        //初始化链表时 数据域和指针域都为空
        public function __construct(){
            $this->data=null;
            $this->next=null;
        }
    }

    //链表类
    class SingelList{
        public $data;
        public $next;
        //链表的长度
        public static $length;

        public function __construct(){
            $this->data=null;
            $this->next=null;
        }

        //清空链表
        public function clearList(){
            if(self::$length>0){
                while($this->next!=null){
                    $tmp=$this->next->next;
                    $this->next=null;
                    unset($this->next);
                    $this->next=$tmp;
                }
                self::$length=0;
            }
        }

        //返回链表的长度
        public function getListLength(){
            return self::$length;
        }

        //判断链表是否为空
        public function isEmpty(){
            return self::$length===0 && $this->next===null ? 'true' : 'false';
        }

        //使用数组初始化链表
        public function createList($array){
            $this->clearList();
            if(is_array($array)){
                foreach($array as $one){
                    $tmp=new List();
                    $tmp->next=$this->next;
                    $tmp->data=$this->one;
                    $this->next=$tmp->next;

                    self::$length++;
                }
            }
            else{
                return false;
            }
        }

        //返回第i个元素
        public function getEle($i){
            if($i>self::$length || $i<1){
                return false;
            }
            $j=1;
            $p=$this->next;
            while($j<$i){
                $p=$p->next;
                ++$j;
            }
            return $p;
        }

        //查找是否存在某元素的值
        public function getValue($value){
            $p=$this;
            $j=1;
            while($p->next!==null && strcmp($p->data,$value)!==0){
                $p=$p->next;
                ++$j;
            }
            if(strcmp($p->data,$value)===0){
                return $j;
            }
            else{
                return -1;
            }
        }

        //链表的插入
        public function insertList($i,$value){
            if($i>self::$length || $i<1){
                return false;
            }
            $j=1;
            while($j<$i && $this->next!==null){
                $j++;
                $this=$this->next;
            }
            $tmp=new List();
            $tmp->data=$value;
            $tmp->next=$this->next;
            $this->next=$tmp;
            ++self::$length;
            return true;
        }

        //删除链表中的某个元素
        public function deleteList($i){
            if($i>self::$length || $i<1){
                return false;
            }
            $j=1;
            while($j<$i){
                $this=$this->next;
            }
            $q=$this->next;
            $this->next=$q->next;
            $q=null;
            unset($q);
            self::$length--;
            return true;
        }
    }
?>
