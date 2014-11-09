var List=new Object;

//初始化一个双向链表，头和尾都指向自己
List.init=function init(list){
    list._idleNext=list;
    list._idlePrev=list;
};

//返回上一个结点
List.peek=function peek(list){
    if(list._idlePrev===list){
        return null;
    }
    return list._idlePrev;
};

//移出并且返回前一个结点
List.shift=function shift(list){
    var first=list._idlePrev;
    list.remove(list);
    return first;
};

//移出结点
List.remove=function remove(item){
    if(item._idleNext){
        item._idleNext._idleNext=item._idlePrev;
    }
    if(item._idlePrev){
        item._idlePrev._idleNext=item._idleNext;
    }
    item._idleNext=null;
    item._idlePrev=null;
};

List.append=function append(list,item){
    list.remove(item);
    item._idleNext=list._idleNext;
    list._idleNext._idlePrev=item;
    item._idlePrev=list;
    item._idleNext=item;
};

List.isEmpty=function isEmpty(list){
    return list._idleNext===list;
};

exports.list=List;
