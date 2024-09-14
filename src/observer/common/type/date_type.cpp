/***************************************************************
 *                                                             *
 * @Author      : Koschei                                      *
 * @Email       : nitianzero@gmail.com                         *
 * @Date        : 2024/9/11                                    *
 * @Description : Brief description of the file's purpose      *
 *                                                             *
 * Copyright (c) 2024 Koschei                                  *
 * All rights reserved.                                        *
 *                                                             *
 ***************************************************************/

#include "date_type.h"

#include <common/value.h>
#include <common/lang/comparator.h>
#include <common/lang/sstream.h>
#include <iomanip>

int DateType::compare(const Value &left, const Value &right) const
{
  return common::compare_int((void *)&left.value_.int_value_, (void *)&right.value_.int_value_);
}

RC DateType::to_string(const Value &val, string &result) const
{
  // 提取年、月、日
  int year  = val.value_.int_value_ / 10000;        // 获取年份
  int month = (val.value_.int_value_ / 100) % 100;  // 获取月份
  int day   = val.value_.int_value_ % 100;          // 获取日期

  // 使用字符串流构建结果字符串
  std::ostringstream oss;
  oss << std::setw(4) << std::setfill('0') << year << '-' << std::setw(2) << std::setfill('0') << month << '-'
      << std::setw(2) << std::setfill('0') << day;

  result = oss.str();  // 将结果赋值给 result
  return RC::SUCCESS; // 假设 RC 是一个枚举类型，表示返回状态
}
