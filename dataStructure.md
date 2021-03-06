# データ構造のまとめ

| データ構造名 | 探索 | ランダムアクセス | 先頭もしくは末尾への挿入 | 特定の位置への挿入 | 先頭もしくは末尾の削除 | 特定の位置の削除 |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| （動的）配列 | O(n) | O(1) | O(1) | O(n) | O(n)
| （双方向）連結リスト | O(n) | O(n) | O(1) | 

## 配列

配列はランダムアクセス（indexを用いた参照）がO(1)で実行できるデータ構造

その代わりに、**特定の位置への挿入**、**特定の位置の削除**が苦手。（末尾への追加は、基本的にO(1)）

* 特定の位置への挿入：**特定の位置を探す**のが(n)、そのあと、**後ろのデータを移す**or**コピーを作成する**のがO(n)
* 削除：**削除対象を探す**のがO(n)、そのあと、**後ろのデータを移す**or**コピー作成する**のがO(n)

## 双方向連結リスト

双方向連結リストは**特定の位置への挿入**、**特定の位置の削除**がO(1)で実行できるデータ構造


